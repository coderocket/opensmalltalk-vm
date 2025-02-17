/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.3166 uuid: bda1c176-bedf-4490-bb95-90d3851c1526
   from
	InternetConfigPlugin VMMaker.oscog-eem.3166 uuid: bda1c176-bedf-4490-bb95-90d3851c1526
 */
static char __buildInfo[] = "InternetConfigPlugin VMMaker.oscog-eem.3166 uuid: bda1c176-bedf-4490-bb95-90d3851c1526 " __DATE__ ;


#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#include "InternetConfigPlugin.h"
#include "sqMemoryAccess.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveGetMacintoshFileTypeAndCreatorFrom(void);
EXPORT(sqInt) primitiveGetStringKeyedBy(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
EXPORT(sqInt) shutdownModule(void);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*methodReturnValue)(sqInt oop);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*stackValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classString(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt isBytes(sqInt oop);
extern sqInt methodReturnValue(sqInt oop);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt stackValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "InternetConfigPlugin VMMaker.oscog-eem.3166 " INT_EXT;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* InternetConfigPlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return sqInternetConfigurationInit();
}

	/* InternetConfigPlugin>>#primitiveGetMacintoshFileTypeAndCreatorFrom: */
EXPORT(sqInt)
primitiveGetMacintoshFileTypeAndCreatorFrom(void)
{
	char *aFileName;
	char creator[8];
	sqInt i;
	sqInt keyLength;
	sqInt oop;
	char *ptr;

	if (!(isBytes(stackValue(0)))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	aFileName = ((char *) (firstIndexableField(stackValue(0))));
	keyLength = byteSizeOf(((sqInt)(sqIntptr_t)(aFileName) - BaseHeaderSize));
	sqInternetGetMacintoshFileTypeAndCreatorFromkeySizeinto(aFileName, keyLength, creator);
	oop = instantiateClassindexableSize(classString(), 8);
	ptr = firstIndexableField(oop);
	for (i = 0; i <= 7; i += 1) {
		ptr[i] = (creator[i]);
	}
	if (!(failed())) {
		methodReturnValue(oop);
	}
	return null;
}

	/* InternetConfigPlugin>>#primitiveGetStringKeyedBy: */
EXPORT(sqInt)
primitiveGetStringKeyedBy(void)
{
	char *aKey;
	char aString[1025];
	sqInt i;
	sqInt keyLength;
	sqInt oop;
	char *ptr;
	sqInt size;

	if (!(isBytes(stackValue(0)))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	aKey = ((char *) (firstIndexableField(stackValue(0))));
	keyLength = byteSizeOf(((sqInt)(sqIntptr_t)(aKey) - BaseHeaderSize));
	size = sqInternetConfigurationGetStringKeyedBykeySizeinto(aKey, keyLength, aString);
	oop = instantiateClassindexableSize(classString(), size);
	ptr = firstIndexableField(oop);
	for (i = 0; i < size; i += 1) {
		ptr[i] = (aString[i]);
	}
	if (!(failed())) {
		methodReturnValue(oop);
	}
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
	sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		byteSizeOf = interpreterProxy->byteSizeOf;
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		isBytes = interpreterProxy->isBytes;
		methodReturnValue = interpreterProxy->methodReturnValue;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		stackValue = interpreterProxy->stackValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* InternetConfigPlugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return sqInternetConfigurationShutdown();
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "InternetConfigPlugin";
void* InternetConfigPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "primitiveGetMacintoshFileTypeAndCreatorFrom\000\000\000", (void*)primitiveGetMacintoshFileTypeAndCreatorFrom},
	{(void*)_m, "primitiveGetStringKeyedBy\000\000\000", (void*)primitiveGetStringKeyedBy},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{(void*)_m, "shutdownModule", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else // ifdef SQ_BUILTIN_PLUGIN

#if SPURVM
EXPORT(signed short) primitiveGetMacintoshFileTypeAndCreatorFromMetadata = 0;
EXPORT(signed short) primitiveGetStringKeyedByMetadata = 0;
#endif // SPURVM

#endif // ifdef SQ_BUILTIN_PLUGIN
