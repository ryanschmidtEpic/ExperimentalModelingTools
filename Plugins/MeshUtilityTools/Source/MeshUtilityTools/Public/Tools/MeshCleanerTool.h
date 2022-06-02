// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseTools/BaseMeshProcessingTool.h"
#include "MeshCleanerTool.generated.h"


UENUM()
enum class EMeshCleanerToolNoiseType : uint8
{
	Random,
	Perlin
};


UCLASS()
class MESHUTILITYTOOLS_API UMeshCleanerProperties : public UInteractiveToolPropertySet
{
	GENERATED_BODY()
public:

	/** Number of edge subdivisions */
	UPROPERTY(EditAnywhere, Category = Subdivisions, meta = (UIMin = "0", UIMax = "5", ClampMin = "0", ClampMax = "10"))
	int Subdivisions = 0;

	UPROPERTY(EditAnywhere, Category = Noise)
	EMeshCleanerToolNoiseType NoiseType = EMeshCleanerToolNoiseType::Perlin;

	/** Scale of the noise */
	UPROPERTY(EditAnywhere, Category = Noise, meta = (UIMin = "-10.0", UIMax = "10.0", ClampMin = "-1000.0", ClampMax = "100.0"))
	float Scale = 5.0f;

	/** Frequency of the noise */
	UPROPERTY(EditAnywhere, Category = Noise, meta = (UIMin = "0", UIMax = "5.0", EditCondition = "NoiseType == EMeshCleanerToolNoiseType::Perlin"))
	float Frequency = 1.0f;

	/** Random Seed */
	UPROPERTY(EditAnywhere, Category = Noise, meta = (UIMin = "0", ClampMin = "0", EditCondition = "NoiseType == EMeshCleanerToolNoiseType::Random"))
	int Seed = 10;

};



/**
 * UMeshCleanerTool applies PN Tessellation and Perlin or Random noise to an input Mesh
 */
UCLASS()
class MESHUTILITYTOOLS_API UMeshCleanerTool : public UBaseMeshProcessingTool
{
	GENERATED_BODY()

public:
	UMeshCleanerTool();

protected:
	// UBaseMeshProcessingTool API implementation

	virtual void InitializeProperties() override;
	virtual void OnShutdown(EToolShutdownType ShutdownType) override;

	virtual TUniquePtr<UE::Geometry::FDynamicMeshOperator> MakeNewOperator() override;

	virtual bool RequiresInitialVtxNormals() const { return true; }
	virtual bool HasMeshTopologyChanged() const override;

	virtual FText GetToolMessageString() const override;
	virtual FText GetAcceptTransactionName() const override;

	// disable scaling to unit dimensions, this is a feature of UBaseMeshProcessingTool that is enabled by default
	virtual bool RequiresScaleNormalization() const { return false; }

protected:
	//  settings for this Tool that will be exposed in Modeling Mode details panel
	UPROPERTY()
	TObjectPtr<UMeshCleanerProperties> NoiseProperties = nullptr;
};




UCLASS()
class MESHUTILITYTOOLS_API UMeshCleanerToolBuilder : public UBaseMeshProcessingToolBuilder
{
	GENERATED_BODY()
public:
	virtual UBaseMeshProcessingTool* MakeNewToolInstance(UObject* Outer) const 
	{
		return NewObject<UMeshCleanerTool>(Outer);
	}
};
