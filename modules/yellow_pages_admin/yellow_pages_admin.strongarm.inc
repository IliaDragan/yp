<?php
/**
 * @file
 * yellow_pages_admin.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function yellow_pages_admin_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_body';
  $strongarm->value = 'Получен запрос на восстановление пароля.

Для восстановление пароля перейдите по ссылке [user:one-time-login-url] или скопируйте ее в адресную строку браузера.';
  $export['user_mail_password_reset_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_subject';
  $strongarm->value = 'Восстановление пароля';
  $export['user_mail_password_reset_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_body';
  $strongarm->value = 'Для Вас создана учетная запись на сайте YP.MD.

Для активации перейдите по ссылке [user:one-time-login-url] или скопируйте ее в адресную строку браузера.

В дальнейшем работа по корректировке информации о Вашем предприятии осуществляется через «Моя учетная запись» в меню на главной странице сайта.

username: [user:name]
password: Ваш пароль';
  $export['user_mail_register_admin_created_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_subject';
  $strongarm->value = 'Для Вас создана учетная запись на сайте YP.MD';
  $export['user_mail_register_admin_created_subject'] = $strongarm;

  return $export;
}
