#pragma once
#include "fnamepool.h"
#include <Windows.h>
#include <vector>
#include<cmath>

#define post_render_index 0x64 //Or 0x65 ??
#define process_event_index 0x45 //Or 0x44 ??

class UObject {
public:
	void** VFTable;
	uint32_t ObjectFlags;
	uint32_t InternalIndex;
	struct uclass* ClassPrivate;
	struct FName NamePrivate;
	UObject* OuterPrivate;

	std::string GetName();
	std::string GetFullName();
	bool IsA(void* target) const;

	void ProcessEvent(void* fn, void* parms);
	std::uintptr_t GetProcessEventAddr() {
		auto vtable = *reinterpret_cast<void***>(this);

		return (std::uintptr_t)vtable[process_event_index];
	}
};

class TUObjectArray {
public:
	BYTE** Objects;
	BYTE* PreAllocatedObjects;
	uint32_t MaxElements;
	uint32_t NumElements;
	uint32_t MaxChunks;
	uint32_t NumChunks;
	UObject* GetObjectPtr(uint32_t id) const;
	UObject* FindObject(const char* name) const;

	UObject* FindObjectByString(const char* name);
	std::vector<UObject*> FindObjectsByString(const char* name);
};

class ufield : public UObject {
public:
	char UnknownData_28[0x8]; // 0x28(0x08)
};

class ustruct : public ufield {
public:
	char pad_30[0x10]; // 0x30(0x10)
	ustruct* SuperStruct; // 0x40(0x8)
	char UnknownData_48[0x80]; // 0x48(0x80)
};
class uclass : public ustruct {
public:
	char UnknownData_B0[0x180]; // 0xb0(0x180)
};

template <class T>
class TArray {
public:
	T* Objects;
	int Count;
	int Size;
};

struct FVector {
	float X, Y, Z;

	FVector() : X(0.f), Y(0.f), Z(0.f) {}

	FVector(float x, float y, float z) : X(x), Y(y), Z(z) {}

	FVector(float InF) : X(InF), Y(InF), Z(InF) {}

	float Size() const { return sqrtf(X * X + Y * Y + Z * Z); }

	float Sum() const { return X + Y + Z; }

	float Size2D() const { return sqrtf(X * X + Y * Y); }

	float SizeSquared() const { return X * X + Y * Y + Z * Z; }

	float DistTo(const FVector& V) const { return (*this - V).Size(); }

	FVector unit() const {
		float mult = (1.f / Size());
		return FVector(X * mult, Y * mult, Z * mult);
	}

	FVector operator+(const FVector& other) const { return FVector(X + other.X, Y + other.Y, Z + other.Z); }

	FVector operator-(const FVector& other) const { return FVector(X - other.X, Y - other.Y, Z - other.Z); }

	FVector operator*(const FVector& V) const { return FVector(X * V.X, Y * V.Y, Z * V.Z); }

	FVector operator/(const FVector& V) const { return FVector(X / V.X, Y / V.Y, Z / V.Z); }

	bool operator==(const FVector& V) const { return X == V.X && Y == V.Y && Z == V.Z; }

	bool operator!=(const FVector& V) const { return X != V.X || Y != V.Y || Z != V.Z; }

	FVector operator-() const { return FVector(-X, -Y, -Z); }

	FVector operator+(float Bias) const { return FVector(X + Bias, Y + Bias, Z + Bias); }

	FVector operator-(float Bias) const { return FVector(X - Bias, Y - Bias, Z - Bias); }

	FVector operator*(float Scale) const { return FVector(X * Scale, Y * Scale, Z * Scale); } const

		FVector operator/(float Scale) const { const float RScale = 1.f / Scale; return FVector(X * RScale, Y * RScale, Z * RScale); }

	FVector operator=(const FVector& V) { X = V.X; Y = V.Y; Z = V.Z; return *this; }

	FVector operator+=(const FVector& V) { X += V.X; Y += V.Y; Z += V.Z; return *this; }

	FVector operator-=(const FVector& V) { X -= V.X; Y -= V.Y; Z -= V.Z; return *this; }

	FVector operator*=(const FVector& V) { X *= V.X; Y *= V.Y; Z *= V.Z; return *this; }

	FVector operator/=(const FVector& V) { X /= V.X; Y /= V.Y; Z /= V.Z; return *this; }

	FVector operator*=(float Scale) { X *= Scale; Y *= Scale; Z *= Scale; return *this; }

	FVector operator/=(float V) { const float RV = 1.f / V; X *= RV; Y *= RV; Z *= RV; return *this; }

	float operator|(const FVector& V) const { return X * V.X + Y * V.Y + Z * V.Z; }

	FVector operator^(const FVector& V) const { return FVector(Y * V.Z - Z * V.Y, Z * V.X - X * V.Z, X * V.Y - Y * V.X); }

	static const FVector ZeroVector;

	static const FVector OneVector;
};

class FRotator {
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;
};

class FVector2D {
public:
	float x = 0.0f, y = 0.0f;
};

class FString : TArray<wchar_t> {
public:
	FString() = default;
	FString(const wchar_t* other) {
		Size = Count = *other ? std::wcslen(other) + 1 : 0;

		if (Size) {
			Objects = const_cast<wchar_t*>(other);
		}
	}

	bool is_valid() const {
		return Objects != nullptr;
	}

	const wchar_t* c_str() const {
		return Objects;
	}

	std::string to_string() const {
		const auto length = std::wcslen(Objects);

		std::string str(length, '\0');
		std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Objects, Objects + length, '?', &str[0]);

		return str;
	}
};

class FLinearColor {
public:
	float r, g, b, a;

	FLinearColor() : r{ 0.f }, g{ 0.f }, b{ 0.f }, a{ 0.f } {}
	FLinearColor(const float r, const float g, const float b, const float a) : r{ r }, g{ g }, b{ b }, a{ a } {}
};
