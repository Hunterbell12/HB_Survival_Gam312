// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Resource_M.h"
#include "Kismet/GameplayStatics.h"
#include "BuildingPart.h"
#include "PlayerWidget.h"
#include "ObjectiveWidget.h"
#include "PlayerCharacter.generated.h"


// Main player character class. Handles movement, camera control, player stats,
// and resource collection through the Interact input.
UCLASS()
class HB_SURVIVAL_GAM312_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float axisValue);
	
	UFUNCTION()
		void MoveRight(float axisValue);

	UFUNCTION()
		void StartJump();
		
	
	UFUNCTION()
		void FindObjects();
		
	UFUNCTION()
		void StopJump();


	UPROPERTY(VisibleAnywhere)
		UCameraComponent* PlayerCamComp;

	// Basic survival stats that can be viewed or changed from Blueprints.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		float Stamina = 100.0f;

	// Individual resource counters.
	UPROPERTY(EditAnywhere, Category = "Resources")
		int Wood;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Stone;


	UPROPERTY(EditAnywhere, Category = "Resources")
		int Berry;

	// Arrays used to store resource amounts and names by index.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		TArray<FString> ResourcesNameArray;

	UPROPERTY(EditAnywhere, Category = "HitMarker")
		UMaterialInterface* hitDecal;

		// Array used to store the building objects that can be built by the player.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Supplies")
		TArray<int> BuildingArray;

		// Boolean used to check if the player is currently building something, which prevents them from building multiple objects at once.
	UPROPERTY()
		bool isBuilding;

		// The class of the building part to spawn, which is set in the editor and used in the SpawnBuilding function.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<ABuildingPart> BuildingPartClass;

		// The building part that is spawned when the player builds something, which is used in the RotateBuilding function to rotate the object while placing it.
	UPROPERTY()
		ABuildingPart* spawnedPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPlayerWidget* playerUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObjectiveWidget* objWidget;

	UPROPERTY()
		float objectsBuilt;

	UPROPERTY()
		float matsCollected;

		// Functions to set the player stats, which can be called from Blueprints to change the stats when certain events happen (like taking damage or eating food).
	UFUNCTION(BlueprintCallable)
		void SetHealth(float amount);

	UFUNCTION(BlueprintCallable)
		void SetHunger(float amount);

	UFUNCTION(BlueprintCallable)
		void SetStamina(float amount);

	UFUNCTION(BlueprintCallable)
	void DecreaseStats();

	// Adds the collected amount to the correct resource entry.
	UFUNCTION()
	void GiveResource(float amount, FString resourceType);

	// Sets the resource amounts for the building menu and checks if the player has enough to build the selected object.
	UFUNCTION(BlueprintCallable)
		void UpdateResources(float woodAmount, float stoneAmount, FString buildingObject);

	UFUNCTION(BlueprintCallable)
		void SpawnBuilding(int buildingID, bool& isSuccess);

	UFUNCTION()
		void RotateBuilding();
};
