; This file was auto-generated by drush make
core = 7.x
api = 2

; Contrib modules
projects[addressfield][version] = "1.2"
projects[addressfield][subdir] = "contrib"

projects[admin_views][version] = "1.5"
projects[admin_views][subdir] = "contrib"

projects[captcha][version] = "1.3"
projects[captcha][subdir] = "contrib"
; https://www.drupal.org/node/2462479
projects[captcha][patch][] = "https://www.drupal.org/files/issues/captcha-7.x-1.x-fix_missing_image-2462479-5.patch"

projects[ckeditor][version] = "1.17"
projects[ckeditor][subdir] = "contrib"

projects[coder][version] = "2.5"
projects[coder][subdir] = "contrib"

projects[colorbox][version] = "2.10"
projects[colorbox][subdir] = "contrib"

projects[ctools][version] = "1.9"
projects[ctools][subdir] = "contrib"

projects[date][version] = "2.9"
projects[date][subdir] = "contrib"

projects[devel][version] = "1.5"
projects[devel][subdir] = "contrib"

projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[email][version] = "1.3"
projects[email][subdir] = "contrib"

projects[entity][version] = "1.7"
projects[entity][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

projects[facetapi][version] = "1.5"
projects[facetapi][subdir] = "contrib"
projects[facetapi][patch][] = "https://www.drupal.org/files/issues/2311585-3-facetapi-7.x-2.x-translate_more_link.patch"
projects[facetapi][patch][] = "http://am.storage.dev.inlead.dk/facetapi_accents-sort.patch"

projects[field_sql_norevisions][version] = "2.1"
projects[field_sql_norevisions][subdir] = "contrib"

projects[features][version] = "2.10"
projects[features][subdir] = "contrib"

projects[features_extra][version] = "1.0"
projects[features_extra][subdir] = "contrib"

projects[file_entity][version] = "2.0-beta2"
projects[file_entity][subdir] = "contrib"

projects[field_group][version] = "1.5"
projects[field_group][subdir] = "contrib"

projects[fontawesome][version] = "2.1"
projects[fontawesome][subdir] = "contrib"

projects[forward][version] = "2.1"
projects[forward][subdir] = "contrib"

projects[geofield][version] = "2.3"
projects[geofield][subdir] = "contrib"

projects[geophp][version] = "1.7"
projects[geophp][subdir] = "contrib"

projects[i18n][version] = "1.15"
projects[i18n][subdir] = "contrib"

projects[l10n_update][version] = "2.0"
projects[l10n_update][subdir] = "contrib"

projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

projects[jquery_update][version] = "2.7"
projects[jquery_update][subdir] = "contrib"

projects[leaflet][version] = "1.3"
projects[leaflet][subdir] = "contrib"

projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

projects[link][version] = "1.4"
projects[link][subdir] = "contrib"

projects[mailsystem][version] = "2.34"
projects[mailsystem][subdir] = "contrib"

projects[media][version] = "2.0-beta5"
projects[media][subdir] = "contrib"

projects[media_ckeditor][version] = "2.x-dev"
projects[media_ckeditor][type] = "module"
projects[media_ckeditor][subdir] = "contrib"
projects[media_ckeditor][download][type] = "git"
projects[media_ckeditor][download][branch] = "7.x-2.x"
; media_ckeditor 7.x-2.0-alpha1+4-dev
; problem adding .pdf file throught ckeditor media plugin.
; https://www.drupal.org/node/2177893
projects[media_ckeditor][download][revision] = "7409f2c0923f7bd81e91303a9d6032505d89d1cf"

projects[media_colorbox][version] = "1.0-rc4"
projects[media_colorbox][subdir] = "contrib"

projects[media_youtube][version] = "3.0"
projects[media_youtube][subdir] = "contrib"

projects[menu_admin_per_menu][version] = "1.1"
projects[menu_admin_per_menu][subdir] = "contrib"

projects[mimemail][version] = "1.0-beta4"
projects[mimemail][subdir] = "contrib"

projects[module_filter][version] = "2.0"
projects[module_filter][subdir] = "contrib"

projects[navigation404][version] = "1.0"
projects[navigation404][subdir] = "contrib"

projects[node_expire][version] = "1.8"
projects[node_expire][subdir] = "contrib"

projects[nodeviewcount][version] = "2.4"
projects[nodeviewcount][subdir] = "contrib"

projects[owlcarousel][version] = "1.6"
projects[owlcarousel][subdir] = "contrib"
projects[owlcarousel][patch][] = "http://am.storage.dev.inlead.dk/owlcarousel-fixed_libraries_owlcarousel_path.patch"

projects[panels][version] = "3.5"
projects[panels][subdir] = "contrib"

projects[recaptcha][version] = "2.2"
projects[recaptcha][subdir] = "contrib"

projects[rules][version] = "2.9"
projects[rules][subdir] = "contrib"

projects[rules_onceperday][version] = "1.2"
projects[rules_onceperday][subdir] = "contrib"

projects[search_api][version] = "1.20"
projects[search_api][subdir] = "contrib"

projects[search_api_solr][version] = "1.11"
projects[search_api_solr][subdir] = "contrib"

projects[service_links][version] = "2.3"
projects[service_links][subdir] = "contrib"

projects[socialfield][version] = "1.4"
projects[socialfield][subdir] = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[taxonomy_menu][version] = "1.5"
projects[taxonomy_menu][subdir] = "contrib"

projects[token][version] = "1.6"
projects[token][subdir] = "contrib"

projects[transliteration][version] = "3.2"
projects[transliteration][subdir] = "contrib"

projects[variable][version] = "2.5"
projects[variable][subdir] = "contrib"

projects[views][version] = "3.13"
projects[views][subdir] = "contrib"

projects[views_autocomplete_filters][version] = "1.2"
projects[views_autocomplete_filters][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.3"
projects[views_bulk_operations][subdir] = "contrib"

projects[bootstrap][version] = "3.0"

; Libraries
libraries[fontawesome][destination]    = "libraries"
libraries[fontawesome][directory_name] = "fontawesome"
libraries[fontawesome][download][type] = "get"
libraries[fontawesome][download][url]  = "https://github.com/FortAwesome/Font-Awesome/archive/v4.6.3.zip"

libraries[leaflet][destination]    = "libraries"
libraries[leaflet][directory_name] = "leaflet"
libraries[leaflet][download][type] = "get"
libraries[leaflet][download][url]  = "http://cdn.leafletjs.com/downloads/leaflet-0.7.3.zip"

libraries[owl-carousel][destination]    = "libraries"
libraries[owl-carousel][directory_name] = "owl-carousel"
libraries[owl-carousel][download][type] = "get"
libraries[owl-carousel][download][url]  = "http://owlgraphic.com/owlcarousel/owl.carousel.zip"

libraries[geoPHP][destination] = "libraries"
libraries[geoPHP][download][type] = "git"
libraries[geoPHP][download][url] = "git@github.com:phayes/geoPHP.git"
libraries[geoPHP][download][tag] = "1.2"

libraries[google_api_php_client][destination] = "modules/yellow_pages_statistics"
libraries[google_api_php_client][directory_name] = "google_api_php_client"
libraries[google_api_php_client][download][tag] = "1.1.6"
libraries[google_api_php_client][download][type] = "git"
libraries[google_api_php_client][download][url] = "https://github.com/google/google-api-php-client.git"

; CKEditor plugins
libraries[widget][destination]    = "modules/contrib/ckeditor/plugins"
libraries[widget][directory_name] = "widget"
libraries[widget][download][type] = "get"
libraries[widget][download][url]  = "http://download.ckeditor.com/widget/releases/widget_4.5.11.zip"

libraries[lineutils][destination]    = "modules/contrib/ckeditor/plugins"
libraries[lineutils][directory_name] = "lineutils"
libraries[lineutils][download][type] = "get"
libraries[lineutils][download][url]  = "http://download.ckeditor.com/lineutils/releases/lineutils_4.5.11.zip"
