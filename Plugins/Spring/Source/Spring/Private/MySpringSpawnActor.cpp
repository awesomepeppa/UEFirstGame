// Fill out your copyright notice in the Description page of Project Settings.


#include "MySpringSpawnActor.h"

// Sets default values
AMySpringSpawnActor::AMySpringSpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EmitFrequeny = 0.1f;
}

// Called when the game starts or when spawned
void AMySpringSpawnActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(EmitParticleTimeHandle, this, &AMySpringSpawnActor::Emit, EmitFrequeny, true);

}

// Called every frame
void AMySpringSpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMySpringSpawnActor::SetEmitFrequeny(float NewEmitFrequeny)
{
	EmitFrequeny = NewEmitFrequeny;
}

void AMySpringSpawnActor::Emit()
{
    FVector Location = GetActorLocation();
    FRotator Rotation = FRotator::ZeroRotator;
    FActorSpawnParameters SpawnParameters;
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

    // Generate a random direction and adjust the location
    FVector Direction;
    AdjustLocationAndDirection(Location, Direction);

    // Energy of the particle
    const float Energy = 800.0f;

    // Spawn the particle actor and apply impulse
    SpawnAndApplyImpulse(Location, Rotation, SpawnParameters, Direction, Energy);
}

// Adjusts the location and direction based on random values
void AMySpringSpawnActor::AdjustLocationAndDirection(FVector& Location, FVector& Direction)
{
    const float Radius = 5.0f;
    const float Height = 5.0f;

    float t = 2.0f * PI * FMath::FRand();
    Location.X += Radius * FMath::Cos(t) * FMath::FRand();
    Location.Y += Radius * FMath::Sin(t) * FMath::FRand();

    Direction = FVector(FMath::Cos(t), FMath::Sin(t), Height);
    Direction.Normalize();
}

// Spawns the particle actor and applies an impulse to it
void AMySpringSpawnActor::SpawnAndApplyImpulse(const FVector& Location, const FRotator& Rotation, const FActorSpawnParameters& SpawnParameters, const FVector& Direction, float Energy)
{
    AMySpringActor* Particle = GetWorld()->SpawnActor<AMySpringActor>(ParticleClass, Location, Rotation, SpawnParameters);
    if (Particle && Particle->StaticMeshComponent)
    {
        Particle->StaticMeshComponent->AddImpulse(Energy * Direction);
    }
}

