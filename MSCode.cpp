#include <windows.h>
#include <fwpmu.h>
#include <accctrl.h>
#include <aclapi.h>
#include <stdio.h>

#pragma comment (lib, "fwpuclnt.lib")
#pragma comment (lib, "advapi32.lib")

#define SESSION_NAME L"SDK Examples"

#define EXIT_ON_ERROR(fnName) \
   if (result != ERROR_SUCCESS) \
   { \
      printf(#fnName " = 0x%08X\n", result); \
      goto CLEANUP; \
   }

DWORD FilterByApp(
         __in HANDLE engine,
         __in PCWSTR filterName,
         __in_opt const GUID* providerKey,
         __in const GUID* layerKey,
         __in_opt const GUID* subLayerKey,
         __in PCWSTR appPath,
         __in FWP_ACTION_TYPE actionType,
         __out_opt UINT64* filterId
         )
{
   DWORD result = ERROR_SUCCESS;
   FWPM_FILTER_CONDITION0 conds[2];
   UINT32 numConds = 0;
   EXPLICIT_ACCESS_W access;
   ULONG sdLen;
   PSECURITY_DESCRIPTOR sd = NULL;
   FWP_BYTE_BLOB sdBlob, *appBlob = NULL;
   FWPM_FILTER0 filter;

   // Add an FWPM_CONDITION_ALE_APP_ID condition if requested.
   if (appPath != NULL)
   {
      // appPath must be a fully-qualified file name, and the file must
      // exist on the local machine.
      result = FwpmGetAppIdFromFileName0(appPath, &appBlob);
      EXIT_ON_ERROR(FwpmGetAppIdFromFileName0);

      conds[numConds].fieldKey = FWPM_CONDITION_ALE_APP_ID;
      conds[numConds].matchType = FWP_MATCH_EQUAL;
      conds[numConds].conditionValue.type = FWP_BYTE_BLOB_TYPE;
      conds[numConds].conditionValue.byteBlob = appBlob;
      ++numConds;
   }
   else
      throw std::exception("appPath is a required parameter!");

   memset(&filter, 0, sizeof(filter));
   // For MUI compatibility, object names should be indirect strings. See
   // SHLoadIndirectString for details.
   filter.displayData.name = (PWSTR)filterName;
   // Link all objects to our provider. When multiple providers are installed
   // on a computer, this makes it easy to determine who added what.
   filter.providerKey = (GUID*)providerKey;
   filter.layerKey = *layerKey;
   // Generally, it's best to add filters to our own sublayer, so we don't have
   // to worry about being overridden by filters added by another provider.
   if (subLayerKey != NULL)
      filter.subLayerKey = *subLayerKey;

   filter.numFilterConditions = numConds;
   
   if (numConds > 0)
      filter.filterCondition = conds;
      
   filter.action.type = actionType;

   result = FwpmFilterAdd0(engine, &filter, NULL, filterId);
   EXIT_ON_ERROR(FwpmFilterAdd0);

CLEANUP:
   FwpmFreeMemory0((void**)&appBlob);
   LocalFree(sd);
   return result;
}