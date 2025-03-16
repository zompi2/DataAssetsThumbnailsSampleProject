# Data Assets Thumbnails for Unreal Engine

**Table of content:**
- [What is DAT plugin?](#what-is-dat-plugin)
- [Which assets can be used as a thumbnail?](#which-assets-can-be-used-as-a-thumbnail)
- [How to set a variable to be an Data Assets' thumbnail?](#which-assets-can-be-used-as-a-thumbnail)
- [How to set that variable using only BP?](#how-to-set-that-variable-using-only-BP)
- [What if I set multiple variables to be a thumbnail?](#what-if-i-set-multiple-variables-to-be-a-thumbnail)
- [What if my thumbnail asset is inside of a struct?](#what-if-my-thumbnail-asset-is-inside-of-a-struct)
- [How to setup default Data Assets color and icon?](#how-to-setup-default-data-assets-color-and-icon)
- [What if thumbnail don't want to change?](#what-if-thumbnail-dont-want-to-change)

## What is DAT plugin?

This plugin allows You to set a variable inside of the Data Asset to be used as a thumbnail of that Data Asset.  
Very useful for games that have many items like weapons, armors, potions etc. described inside of Data Assets.  
Unfortunatelly, vanila Unreal displays all Data Assets using the same icon, which with a lot of them became more difficult
to quickly, visually find the asset you are interested with.  
With this plugin you can set custom thumbnail using the same asset you use to display this asset in the gameplay.

  
**Before Data Asset Thumbnails Plugin**  
![noicons](https://github.com/user-attachments/assets/34304c28-e8e8-41cc-be4f-d9803fb22ab1)

**After Data Assets Thumbnails Plugin**  
![icons](https://github.com/user-attachments/assets/6e039af2-75b7-454d-aad4-f44e6c03fb07)
  
You can also setup different colors for specific Data Asset types and default thumbnails if none is setup:

![deficons](https://github.com/user-attachments/assets/f53f0497-dd84-473c-9c4c-8a4839de0a06)

## Which assets can be used as a thumbnail?

* `UTexture2D` hard and soft reference
* Any `UMaterialInterface` child (`UMaterial`, `UMaterialInstance`, etc) hard and soft referece
* `FSlateBrush`

## How to set a variable to be an Data Assets' thumbnail?  

Simply add `Thumbnail` metadata to the property used to be a thumbnail.

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

## What if I set multiple variables to be a thumbnail?  
The first one found will be used as a thumbnail.  

## What if my thumbnail asset is inside of a struct?  
Unfortunatelly we can't set meta data inside of a struct, but there is a second way of defining which asset should be used as a thumbnail and this is by using `IDataAssetWithThumbnail` and by overriding `GetAssetToRender_Implementation` function.

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

![iconstructbp](https://github.com/user-attachments/assets/054e4c15-842e-46c9-a673-6eb28bddc304)

## How to setup default Data Assets color and icon?  

![defvalues](https://github.com/user-attachments/assets/0f6589d6-e27d-4013-b7ac-53b9dd4f851e)

![defs](https://github.com/user-attachments/assets/106c63fa-f22d-4109-bdcd-adb0c4f9cdb0)  


## What if thumbnail don't want to change?  

Remember that in order to render a thumbnail an asset must be saved and compiled. Sometimes you need to go out from a directory and enter again.  
If everything fails, you can try to refresh a thumbnail, by right clicking the asset and selecting `Asset Actions -> Refresh Thumbnails`. You can also refresh multiple thumbnails  
by right-click on a directory and select `Refresh Thumbnails`.  

![image](https://github.com/user-attachments/assets/68c3146b-8682-4945-81d8-6391142f6ab4) ![refrall](https://github.com/user-attachments/assets/793f7df5-aeea-4593-8234-5340f6c329ab)  





