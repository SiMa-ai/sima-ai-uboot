// SPDX-License-Identifier: GPL-2.0+
/*
 * "... flashing NN%" progress for gzwrite (eMMC recovery flow).
 * Copyright (c) 2026 SiMa.ai
 */

#include <gzip.h>
#include <stdio.h>
#include <linux/types.h>

static int gz_last_pct = -1;

void gzwrite_progress_init(ulong expected_size)
{
	gz_last_pct = -1;
}

/* newline lines in 5% steps: serial-log friendly, no \r overwrites */
void gzwrite_progress(int iteration, ulong bytes_written, ulong total_bytes)
{
	int pct;

	if (!total_bytes)
		return;
	pct = (int)(bytes_written * 100ULL / total_bytes);
	pct -= pct % 5;
	if (pct != gz_last_pct) {
		gz_last_pct = pct;
		printf("... flashing %d%%\n", pct);
	}
}
