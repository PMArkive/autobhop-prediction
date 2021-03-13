#pragma once

using create_interface_fn = void* (*)(const char*, int*);

enum class InterfaceReturnStatus {
	OK,
	FAILED
};
