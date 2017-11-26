// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePhysicsActor.generated.h"

UCLASS()
class WATERINGCAN_API ABasePhysicsActor : public AActor
{
	GENERATED_BODY()

public:
	//Step 2: Expose a float property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BasePhysicsActor")
	float Wetness = 0;

	//Step 3: Expose a boolean property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "BasePhysicsActor")
	bool isDead = false;

	//Step 4: Make a helper function, just because we are lazy
	virtual void CalculateDead();

	//Step 5: Expose a method
	UFUNCTION(BlueprintCallable, Category = "BasePhysicsActor")
	virtual void CalculateWetness(float delta);

	//Step 6: Editor code to make updating values in the editor cleaner
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent) override;
#endif
	
public:	
	// Sets default values for this actor's properties
	ABasePhysicsActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
