#!/usr/bin/php
<?php
if ($argc != 4)
{
	print("Incorrect Parameters");
	return ;
}

if (strstr($argv[2], '+'))
	print($argv[1] + $argv[3]);
if (strstr($argv[2], '-'))
	print($argv[1] - $argv[3]);
if (strstr($argv[2], '*'))
	print($argv[1] * $argv[3]);
if (strstr($argv[2], '/'))
	print($argv[1] / $argv[3]);
if (strstr($argv[2], '%'))
	print($argv[1] % $argv[3]);
print("\n");
?>