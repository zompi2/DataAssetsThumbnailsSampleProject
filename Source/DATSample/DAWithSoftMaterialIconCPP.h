// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DAWithSoftMaterialIconCPP.generated.h"

UCLASS(BlueprintType, Blueprintable)
class DATSAMPLE_API UDAWithSoftMaterialIconCPP : public UDataAsset
{
	GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Thumbnail))
	TSoftObjectPtr<class UMaterialInterface> Icon;
#endif
};
