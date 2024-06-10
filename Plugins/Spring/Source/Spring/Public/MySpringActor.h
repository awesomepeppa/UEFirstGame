// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

#include "MySpringActor.generated.h"

UCLASS()
class SPRING_API AMySpringActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySpringActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particle")
	UStaticMeshComponent* StaticMeshComponent;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particle")
	//float LifeTime = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particle")
    float LifeTime;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	friend class AMySpringSpawnActor;

	UFUNCTION(BlueprintCallable, Category="Particle")
    void SetLifeTime(float NewLifeTime);

private:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particle")
 //   float LifeTime;

	FTimerHandle DestoryTimeHandle;
	void SetDestoryTimeHandle();
	void DestroySelf();
};
