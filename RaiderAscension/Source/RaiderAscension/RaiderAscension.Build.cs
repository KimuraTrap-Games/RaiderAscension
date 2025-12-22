// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RaiderAscension : ModuleRules
{
	public RaiderAscension(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"RaiderAscension",
			"RaiderAscension/Variant_Platforming",
			"RaiderAscension/Variant_Platforming/Animation",
			"RaiderAscension/Variant_Combat",
			"RaiderAscension/Variant_Combat/AI",
			"RaiderAscension/Variant_Combat/Animation",
			"RaiderAscension/Variant_Combat/Gameplay",
			"RaiderAscension/Variant_Combat/Interfaces",
			"RaiderAscension/Variant_Combat/UI",
			"RaiderAscension/Variant_SideScrolling",
			"RaiderAscension/Variant_SideScrolling/AI",
			"RaiderAscension/Variant_SideScrolling/Gameplay",
			"RaiderAscension/Variant_SideScrolling/Interfaces",
			"RaiderAscension/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
