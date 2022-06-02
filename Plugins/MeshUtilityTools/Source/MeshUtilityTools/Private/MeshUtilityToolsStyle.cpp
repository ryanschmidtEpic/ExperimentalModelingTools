// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshUtilityToolsStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateTypes.h"
#include "Styling/CoreStyle.h"
#include "EditorStyleSet.h"
#include "Interfaces/IPluginManager.h"
#include "SlateOptMacros.h"
#include "Styling/SlateStyleMacros.h"

// IMAGE_BRUSH_SVG macro used below needs RootToContentDir to be defined?
#define RootToContentDir StyleSet->RootToContentDir

FString FMeshUtilityToolsStyle::InContent(const FString& RelativePath, const ANSICHAR* Extension)
{
	static FString ContentDir = IPluginManager::Get().FindPlugin(TEXT("MeshUtilityTools"))->GetContentDir();
	return (ContentDir / RelativePath) + Extension;
}

TSharedPtr< FSlateStyleSet > FMeshUtilityToolsStyle::StyleSet = nullptr;
TSharedPtr< class ISlateStyle > FMeshUtilityToolsStyle::Get() { return StyleSet; }

FName FMeshUtilityToolsStyle::GetStyleSetName()
{
	static FName StyleName(TEXT("MeshUtilityToolsStyle"));
	return StyleName;
}

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void FMeshUtilityToolsStyle::Initialize()
{
	const FVector2D DefaultIconSize(20.0f, 20.0f);

	// Only register once
	if (StyleSet.IsValid())
	{
		return;
	}

	StyleSet = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	StyleSet->SetContentRoot(IPluginManager::Get().FindPlugin(TEXT("MeshUtilityTools"))->GetContentDir());
	StyleSet->SetCoreContentRoot(FPaths::EngineContentDir() / TEXT("Slate"));

	StyleSet->Set("MeshUtilityToolsCommands.BeginMeshNoiseTool", new IMAGE_BRUSH_SVG("Icons/NoiseTool", DefaultIconSize));
	StyleSet->Set("MeshUtilityToolsCommands.BeginMeshPlaneCutTool", new IMAGE_BRUSH_SVG("Icons/PlaneTool", DefaultIconSize));
	StyleSet->Set("MeshUtilityToolsCommands.BeginActorClickedBPTool", new IMAGE_BRUSH_SVG("Icons/ClickActorBPTool", DefaultIconSize));
	StyleSet->Set("MeshUtilityToolsCommands.BeginMeshProcessingBPTool", new IMAGE_BRUSH_SVG("Icons/MeshProcessingBPTool", DefaultIconSize));

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
};

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef DEFAULT_FONT

void FMeshUtilityToolsStyle::Shutdown()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}
