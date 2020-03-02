#pragma once

#include <unordered_map>
#include <functional>
#include <chrono>
#include <Windows.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <future>
#include <ctime>

struct Step
{
	Step(POINT lPoint, double lTime)
	{
		point = lPoint;
		timeDelay = lTime;
	};

	POINT point;
	double timeDelay;
};

struct Timer
{
	double ms = 0.0;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;
	bool recordingTime = false;

	void StartTime()
	{
		ms = 0.0;
		seconds = 0;
		minutes = 0;
		hours = 0;
		bool start = false;

		while (!start)
		{
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				start = true;
			}
		}

		while (true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			ms += 2;

			if (ms == 1000)
			{
				seconds++;

				if (seconds == 60)
				{
					minutes++;
					seconds = 0;

					if (minutes == 60)
					{
						hours++;
						minutes = 0;
					}
				}
				ms = 0;
			}
		}
		recordingTime = false;
	}

	double ResetTime()
	{
		double tempMS = (hours * 3600000) + (minutes * 60000) + (seconds * 1000) + ms;

		ms = 0.0;
		seconds = 0;
		minutes = 0;
		hours = 0;

		return tempMS;
	}
};

class Macro
{
public:
	Macro();
	~Macro();

	void AddPoint(POINT point, double time);
	void Execute(bool& continueExecuting);
	void Clear();
	void MouseLeftClick();
	void MouseRightClick();

	std::vector<Step> GetSteps();

	Timer timer;

private:
	std::vector<Step> m_Steps;
};
