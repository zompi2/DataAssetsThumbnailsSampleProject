# Data Assets Thumbnails for Unreal Engine

**Table of content:**
- [What is DAT plugin?](#what-is-dat-plugin)
- [Where can I get this plugin?](#where-can-i-get-this-plugin)
- [Where can I see it in action?](#where-can-i-see-it-in-action)
- [How to set a variable to be a Data Assets thumbnail?](#how-to-set-a-variable-to-be-a-data-assets-thumbnail)
- [How to set that variable using only BP?](#how-to-set-that-variable-using-only-bp)
- [Which assets can be used as a thumbnail?](#which-assets-can-be-used-as-a-thumbnail)
- [What if I set multiple variables to be a thumbnail?](#what-if-i-set-multiple-variables-to-be-a-thumbnail)
- [What if my thumbnail asset is inside of a struct?](#what-if-my-thumbnail-asset-is-inside-of-a-struct)
- [How to setup default Data Assets color and icon?](#how-to-setup-default-data-assets-color-and-icon)
- [What if thumbnail don't want to change?](#what-if-thumbnail-dont-want-to-change)
- [What is inside of the sample project?](#what-is-inside-the-sample-project)
- [How can I get support?](#how-can-i-get-support)
- [Special thanks](#special-thanks)

## What is DAT plugin?

This plugin enhances the Content Browser by allowing you to set custom thumbnail images and colors for your Data Assets, making them easier to organize and identify.  
It's ideal for games with hundreds or thousands of Data Assets like items, abilities, or weapons.  
It helps to organize your assets visually.
  
**Before Data Asset Thumbnails Plugin**  
![prevplug](https://github.com/user-attachments/assets/33402349-039e-4464-b993-8985539842fe)

**After Data Assets Thumbnails Plugin**  
![afterplug](https://github.com/user-attachments/assets/0ab33713-d906-4003-95d9-b9b4e04fa55a)
  
## Where can I get this plugin?  

From Fab: https://www.fab.com/listings/239dd3f5-602e-4453-b161-c06191659335

## Where can I see it in action?  

On YouTube: https://www.youtube.com/watch?v=qIrqWKTJ_nE

## How to set a variable to be a Data Assets thumbnail?  

Simply add `Thumbnail` meta tag to the property you want to use as a thumbnail.

```cpp
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MyDataAsset.generated.h"

UCLASS(BlueprintType, Blueprintable)
class MYPROJECT_API UMyDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Thumbnail))
	TObjectPtr<class UTexture2D> Icon;
};
```

## How to set that variable using only BP?  

If you define a variable inside of the `PrimaryDataAsset` and it is one of the supported type the `Is Thumbnail` checkbox can be selected to make that variable a thumbnail.  
![bpicon](https://github.com/user-attachments/assets/4aa7385d-382e-4401-9cba-5862e0d5c438)  
![det](https://github.com/user-attachments/assets/ce216e1b-692c-46bf-b01f-9f39a7a7059e)  

## Which assets can be used as a thumbnail?

* `UTexture2D` hard and soft reference
* Any `UMaterialInterface` child (`UMaterial`, `UMaterialInstance`, etc) hard and soft referece
* `FSlateBrush`

## What if I set multiple variables to be a thumbnail?  
The first one found will be used as a thumbnail.  

## What if my thumbnail asset is inside of a struct?  
Unfortunatelly we can't set meta tag inside of a struct, but there is a second way of defining which asset should be used as a thumbnail and this is by using `IDataAssetWithThumbnail` and by overriding `GetAssetToRender_Implementation` function.

```cpp
#pragma once

#include "Engine/DataAsset.h"
#include "IDataAssetWithThumbnail.h"
#include "DATUtils.h"
#include "MyDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FIconStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UTexture2D> Icon;
};

UCLASS(BlueprintType, Blueprintable)
class MYPROJECT_API UMyDataAsset : public UDataAsset, public IDataAssetWithThumbnail
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIconStruct IconStruct;

	UObject* GetAssetToRender_Implementation() const override
	{
		return FDATUtils::GetRenderObjectFromObject(IconStruct.Icon);
	}
};
```

**Will it work in BP too?**

Yes it will!

![interface](https://github.com/user-attachments/assets/b49b0948-0e72-4b31-8411-55ece09130f2)

## How to setup default Data Assets color and icon?  

Go to `Project Settings -> Plugins -> Data Assets Thumbnails` and fill up the `Global Overrides`

![settings](https://github.com/user-attachments/assets/11150854-2931-4b45-b197-2c4a61d97cb1)

![deficonsshowcase](https://github.com/user-attachments/assets/237c725a-fbf2-4e94-a5b9-ba96c93b3d3d)

## What if thumbnail don't want to change?  

Remember that in order to render a thumbnail an asset must be saved and compiled. Sometimes you need to go out from a directory and enter again.  
If everything fails, you can try to refresh a thumbnail, by right clicking the asset and selecting `Asset Actions -> Refresh Thumbnails`.  
You can also refresh multiple thumbnails by right-click on a directory and select `Refresh Thumbnails`.  

![image](https://github.com/user-attachments/assets/68c3146b-8682-4945-81d8-6391142f6ab4) ![refrall](https://github.com/user-attachments/assets/793f7df5-aeea-4593-8234-5340f6c329ab)  

## What is inside the sample project?

Sample project contains the c++ and BP definitions of various DataAssets that shows the implementation of DataAssetThumbnails.  
* `Source/DATSample/DACPPDefinitions` - c++ DataAsset definitions with thumbnail properties as SlateBrush, Material, Texture, Struct, Soft Material and Soft Texture.
* `Source/DATSample/GameDADefinitions` - c++ DataAsset definitions of game-like data assets - Boot, Shield, Spell, all heving Texture as a thumbnail property.
* `Content/IconTextures` - textures and materials used for the demo
* `Content/GameAssets` - DataAssets based on `GameDADDefinitions`. They also have the DataAsset color and default icon setup in config.
* `Content/VariousDataAssets/BP/Definitions` - BP DataAsset definitions with thumbnail properties as SlateBrush, Material, Texture, Struct, Soft Material and Soft Texture.
* `Content/VariousDataAssets/BP/Assets` - DataAssets based on the `.../BP/Definitions`
* `Content/VariousDataAssets/CPP` - DataAssets based on the `DACPPDefinitions`

## How can I get support?  

This page consists all of the knowledge you should have to use this plugin.  
However, if you have any questions or bug reports you can:
* Add an [Issue](https://github.com/zompi2/DataAssetsThumbnailsSampleProject/issues) to this repository
* Ask on [Forum page](https://forums.unrealengine.com/t/damian-nowakowski-data-assets-thumbnails/2448537)
* Ask me via e-mail: zompi2@gmail.com

## Special thanks 

I want to say thanks to Monika, for everlasting support and that she always believes in me, and to Patrick, for always encouraging me to get my shit done :)
