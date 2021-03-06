#include "include/helloGPUMaya.h"
#include "include/CudaKernels.h"

const char* HelloGPUMayaCommand::s_commandName = "helloGPUMaya";
const char* HelloGPUMayaCommand::s_author = "Idris Miles";
const char* HelloGPUMayaCommand::s_pluginVersion = "1.0";
const char* HelloGPUMayaCommand::s_mayaVersion = "Any";

HelloGPUMayaCommand::HelloGPUMayaCommand()
{

}

MStatus HelloGPUMayaCommand::doIt(const MArgList&)
{
    // initialization
    unsigned int n = 1000;
    float h_a[n];
    for(unsigned int i=0; i<n; i++)
    {
        h_a[i] = i;
    }

    // print to confirm initialization
    for(unsigned int i=0; i<n; i++)
    {
        MGlobal::displayInfo(MString()+h_a[i]);
    }

    // Run cuda kernel
    CudaKernels::VectorInc(h_a, n);

    // print results
    for(unsigned int i=0; i<n; i++)
    {
        MGlobal::displayInfo(MString()+h_a[i]);
    }


    MGlobal::displayInfo("Hello GPU Maya3!");
    return MS::kSuccess;
}

void* HelloGPUMayaCommand::creator()
{
    return new HelloGPUMayaCommand();
}
