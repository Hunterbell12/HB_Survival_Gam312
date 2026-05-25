// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Resource_M.generated.h"

// Resource actor that can be placed in the level and collected by the player.
UCLASS()
class HB_SURVIVAL_GAM312_API AResource_M : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResource_M();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FString resourceName = "Wood";

	// Amount given to the player each time this resource is collected.
	UPROPERTY(EditAnywhere)
		int resourceAmount = 5;

	// Total amount remaining before this resource is depleted.
	UPROPERTY(EditAnywhere)
		int totalResource = 100;

	// Text shown above or near the resource actor.
	UPROPERTY()
		FText tempText;

	// Component that displays the resource name in the world.
	UPROPERTY(EditAnywhere)
		UTextRenderComponent* ResourceNameTxt;

	// Visible mesh for the resource actor.
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;


};
