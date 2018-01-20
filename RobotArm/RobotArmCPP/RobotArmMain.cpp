///////////////////////////////////////////////////////////////////////////////
// RobotArmMain.cpp
#include "TcPch.h"
#pragma hdrstop

#include "RobotArmMain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CRobotArmMain
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CRobotArmMain
BEGIN_INTERFACE_MAP(CRobotArmMain)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
///</AutoGeneratedContent>
END_INTERFACE_MAP()

IMPLEMENT_ITCOMOBJECT(CRobotArmMain)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CRobotArmMain)
IMPLEMENT_ITCADI(CRobotArmMain)
IMPLEMENT_ITCWATCHSOURCE(CRobotArmMain)


///////////////////////////////////////////////////////////////////////////////
// Set parameters of CRobotArmMain 
BEGIN_SETOBJPARA_MAP(CRobotArmMain)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	SETOBJPARA_VALUE(PID_RobotArmMainParameter, m_Parameter)
	SETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CRobotArmMain 
BEGIN_GETOBJPARA_MAP(CRobotArmMain)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	GETOBJPARA_VALUE(PID_RobotArmMainParameter, m_Parameter)
	GETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CRobotArmMain
BEGIN_OBJPARAWATCH_MAP(CRobotArmMain)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CRobotArmMain
BEGIN_OBJDATAAREA_MAP(CRobotArmMain)
///<AutoGeneratedContent id="ObjectDataAreaMap">
	OBJDATAAREA_VALUE(ADI_RobotArmMainInputs, m_Inputs)
	OBJDATAAREA_VALUE(ADI_RobotArmMainOutputs, m_Outputs)
	OBJDATAAREA_VALUE(ADI_RobotArmMainPlcToCpp, m_PlcToCpp)
	OBJDATAAREA_VALUE(ADI_RobotArmMainCppToPlc, m_CppToPlc)
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
CRobotArmMain::CRobotArmMain()
	: m_Trace(m_TraceLevelMax, m_spSrv)
	, PI(3.14159)
{
///<AutoGeneratedContent id="MemberInitialization">
	m_TraceLevelMax = tlAlways;
	memset(&m_Parameter, 0, sizeof(m_Parameter));
	memset(&m_Inputs, 0, sizeof(m_Inputs));
	memset(&m_Outputs, 0, sizeof(m_Outputs));
	memset(&m_PlcToCpp, 0, sizeof(m_PlcToCpp));
	memset(&m_CppToPlc, 0, sizeof(m_CppToPlc));
///</AutoGeneratedContent>
}

///////////////////////////////////////////////////////////////////////////////
CRobotArmMain::~CRobotArmMain() 
{
}


///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CRobotArmMain)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CRobotArmMain::SetObjStatePS(PTComInitDataHdr pInitData)
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);

	// TODO: Add initialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to OP
//
// Register with other TwinCAT objects
HRESULT CRobotArmMain::SetObjStateSO()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	// TODO: Add any additional initialization


	// If following call is successful the CycleUpdate method will be called, 
	// possibly even before method has been left.
	hr = FAILED(hr) ? hr : AddModuleToCaller(); 

	// Cleanup if transition failed at some stage
	if ( FAILED(hr) )
	{
		RemoveModuleFromCaller(); 
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CRobotArmMain::SetObjStateOS()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;

	RemoveModuleFromCaller(); 

	// TODO: Add any additional deinitialization

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CRobotArmMain::SetObjStateSP()
{
	HRESULT hr = S_OK;
	m_Trace.Log(tlVerbose, FENTERA);

	// TODO: Add deinitialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
HRESULT CRobotArmMain::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;

	// TODO: Replace the sample with your cyclic code
	UpdateInputs();
	//double timerr = m_PlcToCpp.Timer;
	//if ((m_PlcToCpp.Timer > 0) && (m_PlcToCpp.Timer < 5))
	if (timer > 1)
	{
		//m_CppToPlc.TarPosLevelShift = 3 * m_PlcToCpp.Timer;
		m_CppToPlc.TarPosLevelShift = 0;

		//double SetElbowAngle = abs(50 * sin_(timer));
		double SetElbowAngle = -5;
		elbow.SetTargetAngle(SetElbowAngle);
		elbow.run();
	}

	UpdateOutputs();
	return hr;
}
///</AutoGeneratedContent>

void CRobotArmMain::UpdateInputs()
{
	timer = m_PlcToCpp.Timer;
	ElbowUpdateInputs();
}

void CRobotArmMain::UpdateOutputs()
{
	ElbowUpdateOutputs();
}

void CRobotArmMain::ElbowUpdateInputs()
{
	elbow.GetActualAngle(m_PlcToCpp.ElbowAngle - 261);//不受力状态时，角度为261，减去，角度会增大//旧的肘

	//elbow.GetActualAngle(350 - m_Inputs.Angle);//不受力状态时，角度为350，减去，角度会减少//新的肘

}

void CRobotArmMain::ElbowUpdateOutputs()
{
	/* 输出给EL4004，用来控制比例压力阀。压力阀接收电压为0-10V */
	//电压转换为（0-10V）->（0-32767）
	if ((elbow.ShowM1() <= 3) && (elbow.ShowM2() <= 3))
	{
		m_Outputs.ElbowOutM1 = static_cast<int>(elbow.ShowM1() / 10.0 * 32767.0);
		m_Outputs.ElbowOutM2 = static_cast<int>(elbow.ShowM2() / 10.0 * 32767.0);
	}
	else
	{
		m_Outputs.ElbowOutM1 = 0;
		m_Outputs.ElbowOutM2 = 0;
	}

	///* 输出个PLC用来观察的 */
	//if (elbow.ShowAngle() > 0)
	{
		m_CppToPlc.ElbowTarAngle = elbow.ShowTarAngle();
		m_CppToPlc.ElbowAngle = elbow.ShowAngle();
	}
	//m_Outputs.m1v = elbow.ShowM1();
	//m_Outputs.m2v = elbow.ShowM2();
}

void CRobotArmMain::ShoulderElbowUpdateInputs()
{
	PosLevelShift = m_PlcToCpp.PosLevelShift;
	ShoulderInitFinish = m_PlcToCpp.ShoudlerInitFinish;
}

void CRobotArmMain::ShoulderUpdateOutputs()
{
	m_CppToPlc.TarPosLevelShift = TarPosLevelShift;
}

///////////////////////////////////////////////////////////////////////////////
HRESULT CRobotArmMain::AddModuleToCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	if ( m_spCyclicCaller.HasOID() )
	{
		if ( SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spCyclicCaller)) )
		{
			if ( FAILED(hr = m_spCyclicCaller->AddModule(m_spCyclicCaller, THIS_CAST(ITcCyclic))) )
			{
				m_spCyclicCaller = NULL;
			}
		}
	}
	else
	{
		hr = ADS_E_INVALIDOBJID; 
		SUCCEEDED_DBGT(hr, "Invalid OID specified for caller task");
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
VOID CRobotArmMain::RemoveModuleFromCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	if ( m_spCyclicCaller )
	{
		m_spCyclicCaller->RemoveModule(m_spCyclicCaller);
	}
	m_spCyclicCaller	= NULL;

	m_Trace.Log(tlVerbose, FLEAVEA);
}

