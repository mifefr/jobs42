#!/usr/bin/php
<?php

function ft_strlen($str)
{
	$i = 0;

	while ($str[$i] != NULL)
		$i++;
	return ($i);
}

function ft_sp($str)
{
	$array = array_filter(explode(" ", trim($str)), "ft_strlen");
	return $array;
}

function ft_zecho($str)
{
	$i = 1;
	while ($str[$i])
	{
		echo "$str[$i] ";
		$i = $i + 1;
	}
	echo "$str[0]\n";
}

if ($argc > 1)
{
	$argv[1] = trim($argv[1]);
	$argv[1] = str_replace("\t", " ", $argv[1]);
	$argv[1] = eregi_replace("[ ]+", " ", $argv[1]);
	$ok = ft_sp($argv[1]);
	ft_zecho($ok);
}

?>