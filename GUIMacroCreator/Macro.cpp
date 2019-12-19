#include "Macro.h"

Macro::Macro()
{

}

Macro::~Macro()
{

}

void Macro::AddPoint(POINT point, double time)
{
	m_Steps.push_back(Step(point, time));
}

void Macro::Execute()
{
	for (auto& step : m_Steps)
	{
		Sleep(step.timeDelay);
		SetCursorPos(step.point.x, step.point.y);
		MouseLeftClick();
	}
}

void Macro::Clear()
{
	m_Steps.clear();
	m_TotalSteps = 0;
}

void Macro::MouseLeftClick()
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));
	ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));
}

void Macro::MouseRightClick()
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &input, sizeof(INPUT));
	ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &input, sizeof(INPUT));
}

std::vector<Step> Macro::GetSteps()
{
	return m_Steps;
}
