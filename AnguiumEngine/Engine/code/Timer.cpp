#include "AnguiumEngine.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Timer::Timer( void )
{
	m_TimeStart		= 0.0f;
	m_DeltaTime		= 0.0f;
	m_TimePrevious	= 0.0f;
	m_TimeLastFrame = 0.0f;
	m_FPS			= 0;
	m_Frames		= 0;
	m_TotalFrames	= 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Destructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Timer::~Timer( void )
{

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Initializes the kTimer
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Timer::Launch( void )
{
	Reset();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Resets the timer
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Timer::Reset( void )
{
	LARGE_INTEGER ticks;

	m_TimePrevious	= GetTime();
	m_TimeLastFrame = m_TimePrevious;
	m_Frames		= 0;
	m_FPS			= 0;
	m_TotalFrames	= 0;

	QueryPerformanceCounter( &ticks );
	QueryPerformanceFrequency( &m_TickFrequency );

	m_TimeStart = (float)ticks.QuadPart / (float)m_TickFrequency.QuadPart;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Updates the kTimer, calculating the time that has passed since last frame and FPS
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Timer::Update( void )
{
	float timeNow = GetTime();
	m_Frames++;
	m_TotalFrames++;

	if( timeNow - m_TimePrevious > 1.0f )
	{
		m_FPS = m_Frames / (int)(timeNow - m_TimePrevious);
		m_Frames = 0;
		m_TimePrevious = timeNow;
	}

	m_DeltaTime = (timeNow - m_TimeLastFrame);
	m_TimeLastFrame = timeNow;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Desc: Calculates the total time that has passed
Returns:
	float - the total time that has passed
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
float Timer::GetTime( void )
{
	LARGE_INTEGER ticks;
	float time;

	QueryPerformanceCounter(&ticks);

	time = (float)ticks.QuadPart / (float)m_TickFrequency.QuadPart;

	return (time - m_TimeStart);
}