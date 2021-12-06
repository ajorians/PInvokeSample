#pragma once

#ifdef PINVOKE_EXPORTS
#define PINVOKE_API __declspec(dllexport)
#else
#define PINVOKE_API __declspec(dllimport)
#endif
