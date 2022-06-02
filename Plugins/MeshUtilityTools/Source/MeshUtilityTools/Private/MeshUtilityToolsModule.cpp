// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshUtilityToolsModule.h"
#include "MeshUtilityToolsStyle.h"
#include "MeshUtilityToolsCommands.h"

#include "Tools/MeshCleanerTool.h"

#define LOCTEXT_NAMESPACE "FMeshUtilityToolsModule"



// IModuleInterface API implementation

void FMeshUtilityToolsModule::StartupModule()
{
	FMeshUtilityToolsStyle::Initialize();
	FMeshUtilityToolsCommands::Register();

	IModularFeatures::Get().RegisterModularFeature(IModelingModeToolExtension::GetModularFeatureName(), this);
}

void FMeshUtilityToolsModule::ShutdownModule()
{
	IModularFeatures::Get().UnregisterModularFeature(IModelingModeToolExtension::GetModularFeatureName(), this);

	FMeshUtilityToolsCommands::Unregister();
	FMeshUtilityToolsStyle::Shutdown();
}



// IModelingModeToolExtension API implementation

FText FMeshUtilityToolsModule::GetExtensionName()
{
	return LOCTEXT("ExtensionName", "Sample Modeling Extension");
}

FText FMeshUtilityToolsModule::GetToolSectionName()
{
	return LOCTEXT("SectionName", "Extension Demo");
}

void FMeshUtilityToolsModule::GetExtensionTools(const FExtensionToolQueryInfo& QueryInfo, TArray<FExtensionToolDescription>& ToolsOut)
{
	FExtensionToolDescription MeshCleanerToolInfo;
	MeshCleanerToolInfo.ToolName = LOCTEXT("MeshCleanerTool", "MeshCleaner");
	MeshCleanerToolInfo.ToolCommand = FMeshUtilityToolsCommands::Get().BeginMeshCleanerTool;
	MeshCleanerToolInfo.ToolBuilder = NewObject<UMeshCleanerToolBuilder>();
	ToolsOut.Add(MeshCleanerToolInfo);

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMeshUtilityToolsModule, MeshUtilityTools)