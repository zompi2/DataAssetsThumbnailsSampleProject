// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BootAsset.generated.h"

UCLASS(BlueprintType, Blueprintable)
class DATSAMPLE_API UBootAsset : public UDataAsset
{
	GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Thumbnail))
	TObjectPtr<class UTexture2D> Icon;
#endif
};
