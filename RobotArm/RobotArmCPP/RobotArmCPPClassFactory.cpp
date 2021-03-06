///////////////////////////////////////////////////////////////////////////////
// RobotArmCPPClassFactory.cpp
#include "TcPch.h"
#pragma hdrstop

#include "RobotArmCPPClassFactory.h"
#include "RobotArmCPPServices.h"
#include "RobotArmCPPVersion.h"
#include "RobotArmMain.h"

BEGIN_CLASS_MAP(CRobotArmCPPClassFactory)
///<AutoGeneratedContent id="ClassMap">
	CLASS_ENTRY(CID_RobotArmCPPCRobotArmMain, SRVNAME_ROBOTARMCPP "!CRobotArmMain", CRobotArmMain)
///</AutoGeneratedContent>
END_CLASS_MAP()

CRobotArmCPPClassFactory::CRobotArmCPPClassFactory() : CObjClassFactory()
{
	TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_ROBOTARMCPP)); 
#if defined(TCDBG_UNIT_VERSION)
	TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(RobotArmCPP));
#endif //defined(TCDBG_UNIT_VERSION)
}

