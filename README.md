# Data Assets Thumbnails for Unreal Engine Example

This is an example project for the Data Assets Thumbnails plugin: https://github.com/zompi2/UEDataAssetsThumbnails 

## What is inside the sample project?

Sample project contains the c++ and BP definitions of various DataAssets that shows the implementation of DataAssetThumbnails.  
* `Source/DATSample/DACPPDefinitions` - c++ DataAsset definitions with thumbnail properties as SlateBrush, Material, Texture, Struct, Soft Material and Soft Texture.
* `Source/DATSample/GameDADefinitions` - c++ DataAsset definitions of game-like data assets - Boot, Shield, Spell, all heving Texture as a thumbnail property.
* `Content/IconTextures` - textures and materials used for the demo
* `Content/GameAssets` - DataAssets based on `GameDADDefinitions`. They also have the DataAsset color and default icon setup in config.
* `Content/VariousDataAssets/BP/Definitions` - BP DataAsset definitions with thumbnail properties as SlateBrush, Material, Texture, Struct, Soft Material and Soft Texture.
* `Content/VariousDataAssets/BP/Assets` - DataAssets based on the `.../BP/Definitions`
* `Content/VariousDataAssets/CPP` - DataAssets based on the `DACPPDefinitions`
