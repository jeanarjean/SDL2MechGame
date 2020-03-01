#pragma once

struct Frame {
	int x;
	int y;
	int width;
	int height;
	Uint8 duration;
	Uint64 startTime = 0;
};
