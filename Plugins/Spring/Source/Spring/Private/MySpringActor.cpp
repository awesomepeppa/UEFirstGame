// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpringActor.h"

// Sets default values
AMySpringActor::AMySpringActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	RootComponent = StaticMeshComponent;
	StaticMeshComponent->SetSimulatePhysics(true);
	StaticMeshComponent->SetEnableGravity(true);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	StaticMeshComponent->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
	LifeTime = 1.0f;
}

// Called when the game starts or when spawned
void AMySpringActor::BeginPlay()
{
	Super::BeginPlay();
	SetDestoryTimeHandle();
}

// Called every frame
void AMySpringActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMySpringActor::SetLifeTime(float NewLifeTime)
{
	LifeTime = NewLifeTime;
	// Reset the destroy timer with the new lifetime
	SetDestoryTimeHandle();
}

void AMySpringActor::SetDestoryTimeHandle()
{
	UWorld* World = GetWorld();
	World->GetTimerManager().SetTimer(DestoryTimeHandle, this, &AMySpringActor::DestroySelf, LifeTime, false);
}
void AMySpringActor::DestroySelf()
{
	Destroy();
}

