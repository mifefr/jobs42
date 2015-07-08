#!/usr/bin/php
<?php

if ($argc == 1)
{
	print("\n");
	return(0);
}
$i = 0;
$j = 0;
$argv[1] = trim($argv[1]);
$argv[1] = str_replace(CHR(32),"",$argv[1]); 
while($argv[1][$i])
{	
	if(is_otherforms($argv[1][$i]))
	{
		$j++;
		$k = $argv[1][$i];
		if($j > 1)
		{
			print("Syntax Error\n");
			return(0);
		}
	}
	if (!is_numeric($argv[1][$i]) && !is_otherforms($argv[1][$i]))
	{
		print("Syntax Error\n");
		return(0);
	}
	$i++;
}
$ok = explode ($k, $argv[1]);
if (strstr($k, '+'))
	print($ok[0] + $ok[1]);
if (strstr($k, '-'))
	print($ok[0] - $ok[1]);
if (strstr($k, '*'))
	print($ok[0] * $ok[1]);
if (strstr($k, '/'))
	print($ok[0] / $ok[1]);
if (strstr($k, '%'))
	print($ok[0] % $ok[1]);
print("\n");
?>