// Copyright (c) 2025 Damian Nowakowski. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DAWithMaterialIconCPP.generated.h"

UCLASS(BlueprintType, Blueprintable)
class DATSAMPLE_API UDAWithMaterialIconCPP : public UDataAsset
{
	GENERATED_BODY()

public:

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Thumbnail))
	TObjectPtr<class UMaterial> Icon;
#endif
};
