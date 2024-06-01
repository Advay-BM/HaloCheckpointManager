#pragma once
#include "pch.h"
#include "TriggerModel.h"
#include <bitset>

struct TriggerData 
{
	// const
	const std::string name;
	const TriggerModel model;
	const uint32_t triggerIndex;
	const bool isBSPTrigger;

	// changes at run time
	bool lastCheckSuccessful = false;
	std::chrono::time_point<std::chrono::steady_clock> timeLastChecked = std::chrono::steady_clock::now() - std::chrono::minutes(1);

private:
	friend class GetTriggerDataUntemplated;
	explicit TriggerData(std::string triggerName, uint32_t trigIndex, bool isBSP, SimpleMath::Vector3 position, SimpleMath::Vector3 extents, SimpleMath::Vector3 forward, SimpleMath::Vector3 up) 
		: name(triggerName), 
		model(triggerName, position, extents, forward, up),
		triggerIndex(trigIndex),
		isBSPTrigger(isBSP)
	{}
};