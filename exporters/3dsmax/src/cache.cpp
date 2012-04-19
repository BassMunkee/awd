#include "cache.h"
#include <stdlib.h>

BlockCache::BlockCache(void)
{
	firstItem = NULL;
	lastItem = NULL;
}


BlockCache::~BlockCache(void)
{
	// TODO: Free all items
}

void BlockCache::Set(void *key, void *val)
{
	BlockCacheItem *item;

	item = (BlockCacheItem *)malloc(sizeof(BlockCacheItem));
	item->key = key;
	item->val = val;
	item->next = NULL;

	if (!firstItem) {
		firstItem = item;
	}
	else {
		lastItem->next = item;
	}

	lastItem = item;
}

void *BlockCache::Get(void *key)
{
	BlockCacheItem *cur;

	cur = firstItem;
	while (cur) {
		if (cur->key == key)
			return cur->val;

		cur = cur->next;
	}

	return NULL;
}



ColorMaterialCache::ColorMaterialCache(void)
{
	firstItem = NULL;
	lastItem = NULL;
}


ColorMaterialCache::~ColorMaterialCache(void)
{
	// TODO: Free all items
}

void ColorMaterialCache::Set(awd_color color, AWDMaterial *mtl)
{
	ColorMaterialCacheItem *item;

	item = (ColorMaterialCacheItem *)malloc(sizeof(ColorMaterialCacheItem));
	item->color = color;
	item->mtl = mtl;
	item->next = NULL;

	if (!firstItem) {
		firstItem = item;
	}
	else {
		lastItem->next = item;
	}

	lastItem = item;
}

AWDMaterial *ColorMaterialCache::Get(awd_color color)
{
	ColorMaterialCacheItem *cur;

	cur = firstItem;
	while (cur) {
		if (cur->color == color)
			return cur->mtl;

		cur = cur->next;
	}

	return NULL;
}