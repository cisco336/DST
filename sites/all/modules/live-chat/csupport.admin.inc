<?php
/**
 * @file
 * Administrative page callbacks for cSupport Live Chat settings
 * Adds an inline live chat button powered by cSupport
 * to the bottom of all your Drupal pages
 */

/**
 * Implementation of hook_admin_settings_form().
 */
function csupport_admin_settings_form() {
  $form['csupport'] = array(
    '#type' => 'vertical_tabs',
  );

  // General
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#collapsible' => FALSE,
    '#group' => 'csupport',
  );

  $form['general']['csupport_type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#default_value' => 'chat-float-inline',
    '#options' => array(
      'chat-float-inline' => t('Floating Inline Chat Button'),
      'chat-float' => t('Floating Popup Chat Button'),
    ),
    '#required' => TRUE,
  );
  $form['general']['csupport_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Your domain'),
    '#default_value' => variable_get('csupport_id', ''),
    '#size' => 60,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#description' => '<p>' .
      t('Your cSupport domain is your unique cSupport domain, e.g. !example', array('!example' => '<i>yourdomain.csupporthq.com</i>')) .
      '</p><p>' .
      t('No account? Try a free 14-day trial now at !url', array('!url' => '<a href="https://csupporthq.com/pricing/" target="_blank">https://csupporthq.com/pricing/</a>')) .
      '</p>',
  );
  $form['general']['csupport_autofill'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto-fill'),
    '#default_value' => variable_get('csupport_autofill', ''),
    '#required' => FALSE,
    '#description' => '<p>' . t('When users are logged in, auto-fill with their information.'),
  );
  $form['general']['csupport_autostart'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto start session'),
    '#default_value' => variable_get('csupport_autostart', ''),
    '#required' => FALSE,
    '#description' => '<p>' . t('Will only be used if auto-fill as been checked, and there is available information.') . '</p>',
  );
  // END General

  // Layout
  $form['layout'] = array(
    '#type' => 'fieldset',
    '#title' => t('Layout settings'),
    '#collapsible' => TRUE,
    '#group' => 'csupport',
  );
  $form['layout']['csupport_position'] = array(
    '#type' => 'select',
    '#title' => t('Position'),
    '#default_value' => variable_get('csupport_position', ''),
    '#options' => array(
      'b-r' => t('Bottom Right'),
      'b-l' => t('Bottom Left'),
      't-r' => t('Top Right'),
      't-l' => t('Top Left')),
  '#required' => FALSE,
  );
  $form['layout']['csupport_margin'] = array(
    '#type' => 'textfield',
    '#title' => t('Margin from edge'),
    '#default_value' => variable_get('csupport_margin', ''),
    '#size' => 10,
    '#maxlength' => 2,
    '#required' => FALSE,
    '#description' => '<p>' . t('Margin in pixels from edge. Only enter numbers.') . '</p>',
  );

  drupal_add_css('misc/farbtastic/farbtastic.css');
  drupal_add_js('misc/farbtastic/farbtastic.js');
  $form['layout']['csupport_bgcolor'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#default_value' => variable_get('csupport_bgcolor', ''),
    '#size' => 40,
    '#maxlength' => 7,
    '#required' => FALSE,
    '#description' => '<p>' . t('HEX format starting with #.') . '</p>',
    '#suffix' => '<div id="csupport_bgcolor_colorpicker"></div>
<script type="text/javascript">
jQuery(document).ready(function() {
  var colorPicker = jQuery.farbtastic("#csupport_bgcolor_colorpicker",function(color){
    jQuery("#edit-csupport-bgcolor").val(color);
    jQuery("#edit-csupport-bgcolor").css({\'background-color\':color,\'color\':(this.hsl[2]>0.5?\'#000\':\'#fff\')});
  });
  if(/^(#[0-9a-fA-F]{6})$/.test(jQuery("#edit-csupport-bgcolor").val())) colorPicker.setColor( jQuery("#edit-csupport-bgcolor").val());
});
</script>',
  );
  // End Layout

  // Role visibility
  $form['visibility_roles_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Visibility for roles'),
    '#collapsible' => TRUE,
    '#group' => 'csupport',
  );

  $form['visibility_roles_settings']['csupport_visibility_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t("Don't show live chat button for specific roles"),
    '#default_value' => variable_get('csupport_visibility_roles', array()),
    '#options' => user_roles(),
    '#description' => t('Select the roles for which the cSupport Live Chat button should not be shown.'),
  );
  // END Role visibility

  // Page visibility
  $form['visibility_pages_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Visibility in pages'),
    '#collapsible' => TRUE,
    '#group' => 'csupport',
  );

  $form['visibility_pages_settings']['csupport_visibility_pages_type'] = array(
    '#type' => 'radios',
    '#title' => t('Exclude/include live chat button in specific pages'),
    '#options' => array(
      t('Exclude live chat button from listed pages'),
      t('Include live chat button only on listed pages')),
    '#default_value' => variable_get('csupport_visibility_pages_type', 0),
  );
  $form['visibility_pages_settings']['csupport_visibility_pages'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages'),
    '#default_value' => variable_get('csupport_visibility_pages', ''),
    '#description' => t("Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are !blog for the blog page and !blog-wildcard for every personal blog.", array('!blog' => 'blog', '!blog-wildcard' => 'blog/*')),
    '#wysiwyg' => FALSE,
  );
  // END Page visibility

  return system_settings_form($form);
}

/**
 * Implementation of hook_admin_settings_form_validate().
 */
function csupport_admin_settings_form_validate($form, &$form_state) {
  /* Validate that id/domain is correct */
  if (empty($form_state['values']['csupport_id'])) {
    form_set_error('csupport_general', t('You need to use your cSupport domain in the form !example.', array('!example' => '<i>yoursubdomain.csupporthq.com</i>')));
  }

  /* Validate that type selected is correct */
  if ($form_state['values']['csupport_type']!='chat-float-inline' && $form_state['values']['csupport_type']!='chat-float') {
    form_set_error('csupport_general', t('Incorrect value of live chat button type.'));
  }

  /* Validate that margin is in fact an integer */
  if (drupal_strlen($form_state['values']['csupport_margin'])>0 && !is_int($form_state['values']['csupport_margin'])) {
      form_set_error('csupport_general', t('The margin has to be only numbers.'));
  }
}