// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshUtilityToolsCommands.h"
#include "EditorStyleSet.h"
#include "InputCoreTypes.h"
#include "MeshUtilityToolsStyle.h"

#define LOCTEXT_NAMESPACE "MeshUtilityToolsCommands"



FMeshUtilityToolsCommands::FMeshUtilityToolsCommands() :
	TCommands<FMeshUtilityToolsCommands>(
		"MeshUtilityToolsCommands", // Context name for fast lookup
		NSLOCTEXT("Contexts", "MeshUtilityToolsCommands", "Sample Modeling Mode Extension"), // Localized context name for displaying
		NAME_None, // Parent
		FMeshUtilityToolsStyle::Get()->GetStyleSetName() // Icon Style Set
		)
{
}


void FMeshUtilityToolsCommands::RegisterCommands()
{
	UI_COMMAND(BeginMeshCleanerTool, "Cleaner", "Clean the selected Mesh", EUserInterfaceActionType::ToggleButton, FInputChord());
}




#undef LOCTEXT_NAMESPACE
