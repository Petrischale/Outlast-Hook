#pragma once

uintptr_t Aobs(PCHAR pattern, PCHAR mask, uintptr_t begin, SIZE_T size)
{
	SIZE_T patternSize = strlen((char*)mask);

	for (int i = 0; i < size; i++)
	{
		bool match = true;
		for (int j = 0; j < patternSize; j++)
		{
			if (*(char*)((uintptr_t)begin + i + j) != pattern[j] && mask[j] != '?')
			{
				match = false;
				break;
			}
		}
		if (match) return (begin + i);
	}
	return 0;
}