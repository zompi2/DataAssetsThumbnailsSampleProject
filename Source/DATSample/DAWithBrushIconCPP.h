// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DAWithBrushIconCPP.generated.h"

UCLASS(BlueprintType, Blueprintable)
class DATSAMPLE_API UDAWithBrushIconCPP : public UDataAsset
{
	GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Thumbnail))
	FSlateBrush Icon;
#endif
};

