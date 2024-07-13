#pragma once
#include "pch.h"
#include "ScopedServiceRequest.h"
#include "GameState.h"
#include "EngineCommand.h"
#include "UnarySetting.h"
#include "EngineCommandOutputEvent.h"
// Credit to Scales for letting me rip off his console implementation here https://github.com/Scaless/HaloTAS/blob/b9d55d2fe2aff2a1a654984d4d909b5cd14b8780/HaloTAS/MCCTAS/tas_console.h


#ifndef HCM_DEBUG
#error Need to add a destructor guard or something i think - rn the ScopedImFontScaler is getting fubared if hcm shutdown while console open
#endif


struct ConsoleRecord
{
	std::string str;
	enum class Type
	{
		Command,
		Output,
		Error
	}type;
	
};


class CommandConsoleGUI
{
private:
	std::shared_ptr<EngineCommand> engineCommand;

	bool needToScrollToBottom = false;

	std::string mCommandBuffer;
	std::vector<ConsoleRecord> mConsoleRecords;
	int mMaxRecordHistory = 40;


	void clear_buffer();
	void clear_history();

	void render_console_input();
	void render_console_output();

public:
	float fontSize; // CommandConsoleManager will update this whenever the user changes the font size setting
	void render(SimpleMath::Vector2 screenSize); // CommandConsoleManager sets callback to render event that invokes this
	void onCommandOutput(const std::string& outputString); // CommandConsoleManager sets callback to console output event that invokes this
	void onCommandError(const std::string& outputString); // CommandConsoleManager sets callback to console error event that invokes this
	void execute(bool clearBuffer); // CommandConsoleManager sets callback to execute event that invokes this. Also called by CommandConsoleGUI if user presses enter.

	CommandConsoleGUI(
		std::shared_ptr<EngineCommand> engineCommand, 
		float fontSize)
		: engineCommand(engineCommand),
		 fontSize(fontSize)
	{
	}
};