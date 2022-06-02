using UnrealBuildTool;
using System.Collections.Generic;

public class ExperimentalModelingToolsTarget : TargetRules
{
	public ExperimentalModelingToolsTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "ExperimentalModelingTools" } );
	}
}
