// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DAWithColorCPP.generated.h"

UCLASS(BlueprintType, Blueprintable)
class DATSAMPLE_API UDAWithColorCPP: public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Thumbnail))
	FColor Color;
};
