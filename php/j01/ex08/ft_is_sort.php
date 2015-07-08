<?php
function ft_is_sort($tab)
{
	$i = 0;
	if ($tab[1] == NULL)
	{
		return (1);
	}
	while ($tab[$i + 1])
	{
		if ($tab[$i] > $tab[$i + 1])
		{
			return (0);
		}
		$i = $i + 1;
	}
	return (1);
}
?>
