<?php
/**
 * @file
 * yellow_pages_admin.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function yellow_pages_admin_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['en'] = array(
  'user_mail_password_reset_body' => 'Password recovery request has been received.

For password recovery follow the link [user:one-time-login-url] or copy it into your browser.',
  'user_mail_password_reset_subject' => 'Password recovery',
  'user_mail_register_admin_created_body' => 'A new account at YP.MD has been created for you.

You may now log in by clicking this link [user:one-time-login-url] or copying and pasting it into your browser.
In the future the work on updating information about your company will be implemented through "My Account" in the menu on the home page.

User name: [user:name]',
  'user_mail_register_admin_created_subject' => 'A new account at YP.MD has been created for you',
  'user_mail_register_no_approval_required_body' => 'A new account at YP.MD has been created for you.

You may now log in by clicking this link [user:one-time-login-url] or copying and pasting it into your browser.
In the future the work on updating information about your company will be implemented through "My Account" in the menu on the home page.

User name: [user:name]',
  'user_mail_register_no_approval_required_subject' => 'A new account at YP.MD has been created for you',
  'user_mail_status_activated_body' => 'A new account at YP.MD has been created for you.

You may now log in by clicking this link [user:one-time-login-url] or copying and pasting it into your browser.
In the future the work on updating information about your company will be implemented through "My Account" in the menu on the home page.

User name: [user:name]',
  'user_mail_status_activated_subject' => 'A new account at YP.MD has been created for you',
);
  $realm_variables['language']['ro'] = array(
  'user_mail_password_reset_body' => 'Am primit cerere de recuperare a parolei.

Pentru recuperarea parolei urmați link-ul [user:one-time-login-url] sau copiați-l în browser-ul Dvs.',
  'user_mail_password_reset_subject' => 'Restabilirea parolei',
  'user_mail_register_admin_created_body' => 'Pentru Dvs s-a creat un cont pe site-ul YP.MD.

Pentru a-l activa, urmați link-ul [user:one-time-login-url] sau copiați-l în browser-ul Dvs.
În continuare actualizarea informației despre compania Dvs se v-a face prin intermediul "Contul meu" din meniul de pe pagina de start.

Nume de utilizator: [user:name]',
  'user_mail_register_admin_created_subject' => 'Pentru Dvs s-a creat un cont pe site-ul YP.MD',
  'user_mail_register_no_approval_required_body' => 'Pentru Dvs s-a creat un cont pe site-ul YP.MD.

Pentru a-l activa, urmați link-ul [user:one-time-login-url] sau copiați-l în browser-ul Dvs.
În continuare actualizarea informației despre compania Dvs se v-a face prin intermediul "Contul meu" din meniul de pe pagina de start.

Nume de utilizator: [user:name]',
  'user_mail_register_no_approval_required_subject' => 'Pentru Dvs s-a creat un cont pe site-ul YP.MD',
  'user_mail_status_activated_body' => 'Pentru Dvs s-a creat un cont pe site-ul YP.MD.

Pentru a-l activa, urmați link-ul [user:one-time-login-url] sau copiați-l în browser-ul Dvs.
În continuare actualizarea informației despre compania Dvs se v-a face prin intermediul "Contul meu" din meniul de pe pagina de start.

Nume de utilizator: [user:name]',
  'user_mail_status_activated_subject' => 'Pentru Dvs s-a creat un cont pe site-ul YP.MD',
);
  $realm_variables['language']['ru'] = array(
  'user_mail_password_reset_body' => 'Получен запрос на восстановление пароля.

Для восстановление пароля перейдите по ссылке [user:one-time-login-url] или скопируйте ее в адресную строку браузера.',
  'user_mail_password_reset_subject' => 'Восстановление пароля',
  'user_mail_register_admin_created_body' => 'Для Вас создана учетная запись на сайте YP.MD.

Для активации перейдите по ссылке [user:one-time-login-url] или скопируйте ее в адресную строку браузера.
В дальнейшем работа по корректировке информации о Вашем предприятии осуществляется через «Моя учетная запись» в меню на главной странице сайта.

Имя пользователя: [user:name]',
  'user_mail_register_admin_created_subject' => 'Для Вас создана учетная запись на сайте YP.MD',
  'user_mail_register_no_approval_required_body' => 'Для Вас создана учетная запись на сайте YP.MD.

Для активации перейдите по ссылке [user:one-time-login-url] или скопируйте ее в адресную строку браузера.
В дальнейшем работа по корректировке информации о Вашем предприятии осуществляется через «Моя учетная запись» в меню на главной странице сайта.

Имя пользователя: [user:name]',
  'user_mail_register_no_approval_required_subject' => 'Для Вас создана учетная запись на сайте YP.MD',
  'user_mail_status_activated_body' => 'Для Вас создана учетная запись на сайте YP.MD.

Для активации перейдите по ссылке [user:one-time-login-url] или скопируйте ее в адресную строку браузера.
В дальнейшем работа по корректировке информации о Вашем предприятии осуществляется через «Моя учетная запись» в меню на главной странице сайта.

Имя пользователя: [user:name]',
  'user_mail_status_activated_subject' => 'Для Вас создана учетная запись на сайте YP.MD',
);

return $realm_variables;
}
