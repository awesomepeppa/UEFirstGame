// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MySpringActor.h"

#include "MySpringSpawnActor.generated.h"

UCLASS()
class SPRING_API AMySpringSpawnActor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AMySpringSpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "MySpringSpawnActor")
	TSubclassOf<AMySpringActor> ParticleClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "MySpringSpawnActor")
	float EmitFrequeny;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category="MySpringSpawnActor")
    void SetEmitFrequeny(float NewEmitFrequeny);

private:
	FTimerHandle EmitParticleTimeHandle;
	void Emit();
	void AdjustLocationAndDirection(FVector& Location, FVector& Direction);
	void SpawnAndApplyImpulse(const FVector& Location, const FRotator& Rotation, const FActorSpawnParameters& SpawnParameters, const FVector& Direction, float Energy);

};
