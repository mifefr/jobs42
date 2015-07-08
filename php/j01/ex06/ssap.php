#!/usr/bin/php
<?php
function ft_strlen($str)
{
	$i = 0;

	while ($str[$i] != NULL)
		$i++;
	return ($i);
}

function ft_split($str)
{
	$str = trim($str);
	$str = str_replace("\t", " ", $str);
	$str = eregi_replace("[ ]+", " ", $str);
	$array = array_filter(explode(" ", trim($str)), "ft_strlen");
	sort($array, SORT_REGULAR);
	return $array;
}

function ft_zecho($str)
{
	$i = 0;
	while ($str[$i])
	{
		echo "$str[$i]\n";
		$i = $i + 1;
	}
}

$i = 1;
$j = 0;

if (!$argv[1])
	return(0);

while ($argv[$i])
{
	$tab = ft_split(trim($argv[$i++]));
	foreach ($tab as $value) 
	{
		$mega_tab[$j++] = $value;
	}
}	

$i = 0;

if (sort($mega_tab))
	while ($mega_tab[$i])
		print($mega_tab[$i++]."\n");
else
	return(0);
?>