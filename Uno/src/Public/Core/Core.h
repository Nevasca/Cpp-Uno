#pragma once

#define NO_COPY_MOVE(ClassName) ClassName(const ClassName& Other) = delete;\
        ClassName& operator = (const ClassName& Other) = delete;\
        ClassName(ClassName&& Other) = delete;\
        ClassName& operator = (ClassName&& other) = delete;