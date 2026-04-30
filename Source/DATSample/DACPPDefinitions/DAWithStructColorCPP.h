// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

#pragma once

#include "Engine/DataAsset.h"
#include "IDataAssetWithThumbnail.h"
#include "DATUtils.h"
#include "DAWithStructColorCPP.generated.h"

USTRUCT(BlueprintType)
struct FColorStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor LinearColor;
};

UCLASS(BlueprintType, Blueprintable)
class DATSAMPLE_API UDAWithStructColorCPP : public UDataAsset, public IDataAssetWithThumbnail
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColorStruct ColorStruct;

	bool VisualizeWithSolidColor_Implementation() const override
	{
		return true;
	}

	FLinearColor GetColorToRender_Implementation() const override
	{
		return ColorStruct.LinearColor;
	}
};

