// Copyright Maniform Studio

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraEditorTarget : TargetRules
{
	public AuraEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

        // Add this line for the include order version
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        ExtraModuleNames.AddRange( new string[] { "Aura" } );
	}
}
