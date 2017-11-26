// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePhysicsActor.h"


// Sets default values
ABasePhysicsActor::ABasePhysicsActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePhysicsActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePhysicsActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Step 1: Implement the CalculateHealth function.
void ABasePhysicsActor::CalculateWetness(float Delta)
{
	Wetness += Delta;
	CalculateDead();
}

//Step 2: Implement the CalculateDead function.
void ABasePhysicsActor::CalculateDead()
{
	if (Wetness <= 0) {
		isDead = true;
		Wetness = 0;
	} else {
		isDead = false;
	}
}
#if WITH_EDITOR
//Step 3: Implement the remainder of our helper code, used by the editor when we change values.
void ABasePhysicsActor::PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent)
{
	isDead = false;
	Wetness = 0;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();
}
#endif

