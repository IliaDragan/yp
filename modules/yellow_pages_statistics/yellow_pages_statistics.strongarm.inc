<?php
/**
 * @file
 * yellow_pages_statistics.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function yellow_pages_statistics_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_service_account_email';
  $strongarm->value = 'cricunova@utility-mapper-119014.iam.gserviceaccount.com';
  $export['google_service_account_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'google_service_account_keys';
  $strongarm->value = '0�	�0�	b	*�H��
���0��0(
*�H��
��6�����?N�C��P{����j/	ܕ�E�m	`�����\'�)n��H�Od�s1��iU��*y�t�q�uB|���T`6 ���2z\'��?fݮ��>\'s�^��x\'Ռ
�����a�("GC��8"���t�F�y8�yy�' . "\0" . '���4Iܨ���	ѥ�1�:��i$$���{F�q��44�bz��}��z@,7e��#(��e�J�Ҷ��2a��X��*	"=w�>Q�hV+l�my�d�]oJ����M:2nc<�l�E�� dR�p��@���ǐ�6��D)�{8� )8Ǣ��E�\\�
�G��iNV�ů�u�)�Y�U�N^�#�Y?���葓�܏�Y' . "\0" . 'Ԙ��-��"��"�ˍ�Rŋ��&;�be��|�%Ff
�MlJDx�����za��^��|`}��1X&
���$�
~�d��  
b�z�Y���/c�JA��
*�H��
(1��JyTck�A}�m�͒<�����>�
���y��Oڠ�?M4�9Nޜ�!�n' . "\0" . '�����F?G���7A#�p�P����f���.{]j�Q����F�H!��w�T$k��.{/꯮-Q�d�߫�em�]���GoQc�U�r�m[\'�Q����9vpNi診��E�����\\il|�ϗ�����Z�{wC��s����x	�r5R���V�&F��4}r�R�3r���|̷��x��r����ݭt�(�' . "\0" . '��3��s�oa՜�(Md
i&+�fԠ٠5#R��(�oFp�-�ʫ���,i���*~֢��\\Me\\� ��X@~kt�d��T+�<fB�އ4��XT����H�(}F��KO���vu=W�[��ã	�p�����GB����aCB8.���F8��?\'�ɶA�OH�hfɏ��B��p�x�>�7q�ML ��85�"��
����l�TS/�N��@q���z�yȠ������|9�k��e�hd�?�0���1����o�عP����9�4Tv���k�tu8kI[�g/[S?�)��oZa�.i��Ji5��ߣW�ak������0=0!0	+' . "\0" . '@�h#�x��r��=���U./wN��w{�=��D����Aؽ' . "\0" . '';
  $export['google_service_account_keys'] = $strongarm;

  return $export;
}