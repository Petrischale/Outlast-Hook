#include "engine.h"

std::string UObject::GetName() {
	return NamePrivate.GetName();
}


std::string UObject::GetFullName() {
	std::string name;
	for (auto outer = OuterPrivate; outer; outer = outer->OuterPrivate) { name = outer->GetName() + "." + name; }
	name = ClassPrivate->GetName() + " " + name + this->GetName();
	return name;
}

void UObject::ProcessEvent(void* fn, void* parms) {
	auto vtable = *reinterpret_cast<void***>(this);
	reinterpret_cast<void(*)(void*, void*, void*)>(vtable[process_event_index])(this, fn, parms);
}

UObject* TUObjectArray::GetObjectPtr(uint32_t id) const {
	if (id >= NumElements) return nullptr;
	uint64_t chunkIndex = id / 65536;
	if (chunkIndex >= NumChunks) return nullptr;
	auto chunk = Objects[chunkIndex];
	if (!chunk) return nullptr;
	uint32_t withinChunkIndex = id % 65536 * 24;
	auto item = *reinterpret_cast<UObject**>(chunk + withinChunkIndex);
	return item;
}

UObject* TUObjectArray::FindObject(const char* name) const {
	for (auto i = 0u; i < NumElements; i++) {
		auto object = GetObjectPtr(i);
		if (object && object->GetFullName() == name) { return object; }
	}
	return nullptr;
}

UObject* TUObjectArray::FindObjectByString(const char* name) {
	for (auto i = 0u; i < NumElements; i++) {
		auto object = GetObjectPtr(i);
		if (object && object->GetFullName().find(name) != std::string::npos) { return object; }
	}
	return nullptr;
}

std::vector<UObject*> TUObjectArray::FindObjectsByString(const char* name) {
	std::vector<UObject*> res;
	for (auto i = 0u; i < NumElements; i++) {
		auto object = GetObjectPtr(i);
		if (object && object->GetFullName().find(name) != std::string::npos) { 
			res.push_back(object);
		}
	}
	return res;
}

bool UObject::IsA(void* target) const {
	for (auto super = ClassPrivate; super; super = static_cast<uclass*>(super->SuperStruct)) {
		if (super == target) {
			return true;
		}
	}
	return false;
}