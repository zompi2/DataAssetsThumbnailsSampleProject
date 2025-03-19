// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

using UnrealBuildTool;

public class DATSample : ModuleRules
{
	public DATSample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput", 
			"SlateCore", 
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		
		if (Target.bBuildEditor == true)
        {
            PublicDependencyModuleNames.AddRange(new string[] 
			{ 
				"DataAssetsThumbnails",
				"UnrealEd"
			});
        }

	}
}
