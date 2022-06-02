using UnrealBuildTool;
using System.Collections.Generic;

public class ExperimentalModelingToolsEditorTarget : TargetRules
{
	public ExperimentalModelingToolsEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "ExperimentalModelingTools" } );
	}
}
